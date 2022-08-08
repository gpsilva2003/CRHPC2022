# MPI

This repository presents the source codes used in the course of Costa Rica High Performance Computing
School 2002. Additionally we present a support text for the preparation of the MPI execution environment.

## MPI executing environment setup

We present here a brief guide on installing and configuring the
MPI library, as well as running an MPI program on some
Posix operating system distributions.

### Introduction

At first, we must consider that there are several implementations available for MPI, some of them free and other commercial. The processor and the interconnection network used by the system where the applications will be executed are some of the factors to be considered when choosing the appropriate distribution of MPI. Eventually, some distributions support more than one type of processor or network interface, which gives them a greater possibility of adapting to the characteristics of your system.


It is important to note that processor architectures change from generation to generation, with the inclusion of new instructions and facilities.
A very common trend has been to improve the ability to processor vector processing, which has a great impact on the final performance of scientific applications.

Some commercial compilers, such as Intel and PGI, can generate code optimized for different processor architectures in a single executable, alleviating the need to generate separate binary code for each processor type. The open source compiler GNU only supports this facility in newer versions. Here are some of the most important distributions:

-   OpenMPI - Maintained by a group of different partners in the academic, research and industry area including AMD, Bull, Cisco Systems, Stuttgart High Performance Computing Center (HLRS), IBM, Intel, Los Alamos National Laboratory and NVIDIA. Available at <https://www.open-mpi.org/>

-   MPICH - It is also maintained by a group of partners from the academic, research and industry areas. It targets high performance systems and supports various compilers such as GNU, LLVM, Clang, Intel, PGI and Sun Studio. Available at <http://www.mpich.org/>

-   MVAPICH2 - It is an implementation derived from MPICH and maintained by
     Ohio State University focused on high-end applications
     performance using interconnection networks such as
     OpenFabrics-IB, Omni-Path, OpenFabrics-iWARP, PSM and TCP/IP.
     Available at <http://mvapich.cse.ohio-state.edu/>

-   Intel® MPI Library - It is a message exchange library that
     implements the open source MPICH specification, which is maintained and
     distributed by Intel. It has a free version for students,
     academics and researchers. Available in
     <https://software.intel.com/en-us/qualify-for-free-software>

The use of parallel programs adds a complexity factor relative to the type of interconnection network used by the computing system on which the MPI parallel program will be executed. Most current implementations of MPI include support for multiple network types in a single executable program, so that it can run with different types of interconnect network without recompilation.

Depending on your equipment, application and features available, one implementation may be better than the other. These distributions evolve over time, but at the time of writing, the following characteristics can be highlighted.

OpenMPI is quite flexible in terms of *hardware* platforms, with support for Infiniband, but the overall performance is slightly lower than other implementations like Intel MPI and MVAPICH2. OpenMPI also supports the Cray Gemini network, but it is not an implementation officially supported by Cray.

MPICH is a reference implementation, being considered one of the most popular implementations of the MPI standard, serving as the basis for a series of derived implementations such as IBM MPI, Cray MPI, Intel MPI and MVAPICH, among others. However, its support for InfiniBand is poor, unlike OpenMPI. But its variants like Intel MPI and MVAPICH2 have quite efficient support for InfiniBand. If we consider the MPICH suite and its variants, the network support is extremely varied, including both InfiniBand and proprietary interconnect networks such as Cray Seastar, Gemini and Aries, such as IBM Blue Gene (/L, /P and /Q).

MVAPICH2 is optimized for InfiniBand, but it doesn't have a good affinity between processes and cores in environments with multiple *threads*.

Intel MPI has good performance and a lot of flexibility in terms of the types of processors and networks supported, but it is a commercial product that requires the purchase of a license to use it. Other than Microsoft, it is the only supported MPI implementation for the Windows operating system.

On an axis orthogonal to the support of the *hardware* platform, we find the coverage of the MPI standard. In this sense, the MPICH implementation is far superior. MPICH was the first implementation to support every release of the MPI standard, from MPI-1 to MPI-3. OpenMPI only recently supports the MPI-3 version and even then partially (it doesn't support the "external32" format of MPI I/O, for example) and has problems on some platforms. Both OpenMPI and MPICH have full support for MPI_THREAD_MULTIPLE, ie if the process is "multithreaded", multiple *threads* can use the MPI library without restrictions.

Finally, in terms of process management, where OpenMPI was much better some time ago, now MPICH's new process manager, Hydra, is just as good and has the same usability and facilities as OpenMPI's ORTE. The old MPICH managed, called MPD, was difficult to use and without many options, but it was deprecated a few years ago.
More information about OpenMPI and MPICH can be found at
<https://github.com/open-mpi/ompi/blob/master/README.md> and
<https://www.mpich.org/documentation/guides/>, respectively

### Instalation

Let's consider how to install and configure both
most major distributions available as code software
open and free: OpenMPI and MPICH. Fortunately most of
Linux distributions already have packages available for installing these versions, which makes this task much easier.

#### Fedora, CentOS and similar ones 

Basically, the various types of MPI implementations can be installed directly from the repository.

-   **OpenMPI**

    ``` {}
    $ sudo dnf install openmpi
    $ sudo dnf install openmpi-devel
    ```

-   **MPICH**

    ``` {}
    $ sudo dnf install mpich
    $ sudo dnf install mpich-devel
    ```

#### Ubuntu, Debian and similar ones

-   **OpenMPI**

    Basically, install OpenMPI from repository:

    ``` {}
    $ sudo apt-get install openmpi-bin
    $ sudo apt-get install openmpi-doc
    $ sudo apt-get install libopenmpi-dev
    ```

-   **MPICH**

    Instale o pacote MPICH diretamente do repositório:

    ``` {}
    $ sudo apt-get install mpich
    $ sudo apt-get install mpich-doc
    $ sudo apt-get install libmpich-devel
    ```

#### MacOS 

-   **OpenMPI**

 Automated installation of OpenMPI is possible on MacOS with the
     *homebrew* program installation, at <https://brew.sh/>,
     with the following command:

    ``` {}
    $ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```

    E então digitar o seguinte comando:

    ``` {}
    $ brew install open-mpi
    ```

-   **MPICH**

    Automated installation of MPICH is possible on MacOS with the
     *homebrew* program installation, at <https://brew.sh/>,
     with the following command:

    ``` {}
    $ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```

And then type the following command:

    ``` {}
    $ brew install mpich
    ```

#### Windows

On Windows, the preferred option is to use the Cygwin terminal emulator or Windows Subsystem for Linux (WSL) for Windows 10. Both provide an interface similar to most HPC clusters.

If you decide to use Cygwin, you will need to install some packages using the Cygwin installer.
If you already have Cygwin installed, you should run the installer and make sure the following packages are selected:

    - gcc-core e gcc-fortran
    - openmpi, libopenmpi40, libopenmpihf08_40, libopenmpiusef08_40, openmpi-devel e openmpi-devel.
    - zlib e zlib-devel
    - make e cmake
    - git
    - vim ou seu editor de texto preferido

You can verify if it works by compiling any C or Fortran program using the *mpicc* or *mpifort* compiler.

On Windows, if you use Visual Studio, you can install Microsoft MPI. The download includes two files,
*msmpisetup.exe* and *msmpisdk.msi*. Download and run both installers. Follow these instructions to create a project
with the compiler and the MPI library.

Also, you can use WSL as an option too. But in this case you must follow the instructions according to the Linux distribution used. 
See more information on <https://docs.microsoft.com/en-us/windows/wsl/install>.

### Compilação 

To compile a source file name *prog.c*, type:
``` {}
$ mpicc -o prog prog.c
```

To compile a file in Fortran, the following commands are possible:

``` {}
$ mpif77 -o prog prog.f
$ mpif90 -o prog prog.f90
```

### Configuring  SSH 

To run in environments with a small number of machines connected via the network, it is important to configure the environment so that it is not necessary to use passwords each time we execute a command on another machine. For this, you must create and configure the use of SSH keys for all machines on the network. In this example, we assume that there are 2 machines named *machine1* and *machine2*, and a username *gabriel*.

First we create the \$HOME/.ssh directory with the command:

``` {}
maquina1:~$ mkdir $HOME/.ssh
```

E em seguida geramos uma chave púbica e uma chave privada com o comando:

``` {}
maquina1:~$ ssh-keygen -t rsa -b 4096 -C "gabriel@exemplo.edu"
```

Pressione a tecla "Entre" para responder às perguntas seguintes com o
padrão.

``` {}
Enter file in which to save the key (/home/gabriel/.ssh/id_rsa): [Press enter]
Enter passphrase (empty for no passphrase): [Type a passphrase]
Enter same passphrase again: [Type passphrase again]
Your identification has been saved in /home/gabriel/.ssh/id_rsa.
Your public key has been saved in /home/gabriel/.ssh/id_rsa.pub.
The key fingerprint is:
01:0f:f4:3b:ca:85:d6:17:a1:7d:f0:68:9d:f0:a2:db Seu_email@exemplo.edu
```

Copie agora a chave pública, $id\_rsa.pub$, para o arquivo
$authorized\_keys$ de modo a permitir o acesso a essa máquina.

``` {}
maquina1:~$ cd ~/.ssh
maquina1:~/.ssh$ cat id_rsa.pub >> authorized_keys
```

Na máquina 2, deve ser criado também um diretório \midtilde{~}$/.ssh$, novamente
com o comando:

``` {}
maquina2:~$ mkdir ~/.ssh
```

Agora, você deve enviar a chave privada, $id\_rsa$, e a chave pública
$id\_rsa.pub$, da máquina 1 para máquina 2, usando o comando *scp* para
isso:

``` {}
maquina1:~$ scp ~/.ssh/id_rsa gabriel@maquina2:~/.ssh/
maquina1:~$ scp ~/.ssh/id_rsa.pub gabriel@maquina2:~/.ssh/
```

Agora, copie o arquivo $id\_rsa.pub$ para o arquivo $authorized\_keys$,
de modo que a máquina 1 possa fazer acesso à maquina 2 sem uso de senha:

``` {}
maquina2:~$ cd ~/.ssh
maquina2:~/.ssh$ cat id_rsa.pub >> authorized_keys
```

#### Executando um programa 

Para executar o programa, digamos, com 4 processos, devemos copiar o
executável para o seu diretório de trabalho e digitar:

``` {}
$ mipexec -n 4 prog
```

O comando $mpiexec$ permite opções mais elaboradas:

``` {}
$ mpiexec -n 1 -host paraty : -n 19 prog
```

Dispara o processo com ranque 0 na máquina "paraty" e outros 19
processos divididos entre as demais máquinas. Para executar através de
múltiplas máquinas:

``` {}
$ mpiexec --hostfile hostfile -n 4 prog
```

Onde *hostfile* é um arquivo contendo o nome ou IP das máquinas onde
deseja executar a aplicação, por exemplo:

``` {}
paraty:2
charitas:3
barra:2
```

Onde o número ao lado do nome de cada máquina indica o total de
processos a serem executados. Os comentários neste arquivo são
precedidos com o caractere "\#". Para saber mais opções, digite:

``` {}
$ mpiexec --help
```

#### Gerenciador de Recursos 

Gerenciadores de recursos como SGE, PBS, SLURM são comuns em muitos
*clusters* gerenciados. Nesse caso, o MPI detecta a sua existência e
interage automaticamente com eles. No caso do PBS, você pode criar um
arquivo *script* como a seguir:

``` {}
# declarar um nome para esta tarefa como sample_job
#PBS -N my_parallel_job
# solicita que a tarefa seja executada na fila com nome parallel
#PBS -q parallel
# solicita um total de 4 processadores para esta tarefa (2 nós e 2 processadores por nó)
#PBS -l nodes=2:ppn=2
# solicita 4 horas de tempo de processador
#PBS -l cput=0:04:00
# combina a saída padrão e a saída de erro do PBS
#PBS -j oe
# envia um email quando a tarefa inicia e quando ela termina e aborta
#PBS -m bea
# especifica o seu endereço de e-mail
#PBS -M John.Smith@dartmouth.edu
#muda para o diretório onde a sua tarefa vai ser submetida
cd $PBS_O_WORKDIR
#inclui o caminho completo com o nome do programa MPI a ser executado
mpirun -machinefile $PBS_NODEFILE -np 4 /path_to_executable/program_name
exit 0
```

As tarefas podem ser submetidas como:

``` {}
$ qsub -l nodes=2:ppn=2 teste.sub
```

O **mpiexec** vai saber automaticamente da existência do PBS no sistema
e pergunta o número total de processadores alocados (4 no caso), e quais
nós foram alocados para o processamento da tarefa. O uso é similar para
outros gerenciadores de recurso. Mais opções para o comando **qsub**
podem ser encontradas em <https://www.jlab.org/hpc/PBS/qsub.html>.
