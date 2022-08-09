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

Install the MPICH package directly from the repository:

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

### Compilation 

To compile a source file name *prog.c*, type:
``` {}
$ mpicc -o prog prog.c
```

To compile a file in Fortran, the following commands are possible:

``` {}
$ mpif77 -o prog prog.f
$ mpif90 -o prog prog.f90
```

### Configuring SSH 

To run in environments with a small number of machines connected via the network, it is important to configure the environment so that it is not necessary to use passwords each time we execute a command on another machine. For this, you must create and configure the use of SSH keys for all machines on the network. In this example, we assume that there are 2 machines named *machine1* and *machine2*, and a username *gabriel*.

First we create the \$HOME/.ssh directory with the command:

``` {}
maquina1:~$ mkdir $HOME/.ssh
```

And then we generate a public key and a private key with the command:

``` {}
maquina1:~$ ssh-keygen -t rsa -b 4096 -C "gabriel@exemplo.edu"
```

Press the "Enter" key to answer the following questions with the
pattern.

``` {}
Enter file in which to save the key (/home/gabriel/.ssh/id_rsa): [Press enter]
Enter passphrase (empty for no passphrase): [Type a passphrase]
Enter same passphrase again: [Type passphrase again]
Your identification has been saved in /home/gabriel/.ssh/id_rsa.
Your public key has been saved in /home/gabriel/.ssh/id_rsa.pub.
The key fingerprint is:
01:0f:f4:3b:ca:85:d6:17:a1:7d:f0:68:9d:f0:a2:db Seu_email@exemplo.edu
```
Now copy the public key, $id\_rsa.pub$, into the file
$authorized\_keys$ to allow access to that machine.

``` {}
maquina1:~$ cd ~/.ssh
maquina1:~/.ssh$ cat id_rsa.pub >> authorized_keys
```

On maquina2, a \midtilde{~}$/.ssh$ directory must also be created, again
with the command:

``` {}
maquina2:~$ mkdir ~/.ssh
```

Now, you must send the private key, $id\_rsa$, and the public key
$id\_rsa.pub$, from maquina1 to maquina2, using the *scp* command to
that:

``` {}
maquina1:~$ scp ~/.ssh/id_rsa gabriel@maquina2:~/.ssh/
maquina1:~$ scp ~/.ssh/id_rsa.pub gabriel@maquina2:~/.ssh/
```

Now copy the $id\_rsa.pub$ file to the $authorized\_keys$ file,
so that maquina1 can access maquina2 without using a password:

``` {}
maquina2:~$ cd ~/.ssh
maquina2:~/.ssh$ cat id_rsa.pub >> authorized_keys
```

#### Executing a program 

To run the program, let's say, with 4 processes, we must copy the
executable to your working directory and type:

``` {}
$ mipexec -n 4 prog
```

The $mpiexec$ command allows for more elaborate options:

``` {}
$ mpiexec -n 1 -host paraty : -n 19 prog
```

This command start the process with rank '0' on the "paraty" machine and another 19 processes divided among the other machines. To run across multiple machines use the $hostfile$ option:

``` {}
$ mpiexec --hostfile maquinas -n 4 prog
```

Where *maquinas* is a file containing the name or IP of the machines where you want to run the application, for example:

``` {}
paraty:2
charitas:3
barra:2
```

The number next to each machine name indicates the total number of
processes to be performed. The comments in this file are
preceded with the character "\#". For more options, type:

``` {}
$ mpiexec --help
```

#### Resource Manager
Resource managers like SGE, PBS, SLURM are common in many managed *clusters*. In this case, the MPI detects their existence and automatically interacts with them. In the case of PBS, you can create a *script* file as follows:

``` {}
# declare a name for this job as sample_job
#PBS -N my_parallel_job
# requests the task to run on the queue named parallel
#PBS -q parallel
# requests a total of 4 processors for this task (2 nodes and 2 processors per node)
#PBS -l nodes=2:ppn=2
# requests 4 hours of processor time
#PBS -l cput=0:04:00
# combines standard output and PBS error output
#PBS -j oe
# sends an email when the task starts and when it ends and aborts
#PBS -m bea
# specify your email address
#PBS -M gabriel@ic.ufrj.br
# changes to the directory where your task will be submitted
cd $PBS_O_WORKDIR
# includes the full path with the name of the MPI program to be executed
mpirun -machinefile $PBS_NODEFILE -np 4 /path_to_executable/program_name
exit 0
```

Tasks can be submitted as:

``` {}
$ qsub -l nodes=2:ppn=2 teste.sub
```

**mpiexec** will automatically know about the existence of PBS on the system and ask for the total number of allocated processors (4 in this case), and which nodes were allocated to process the task. Usage is similar for other resource managers. More options for the **qsub** command can be found at <https://www.jlab.org/hpc/PBS/qsub.html>.

You can have more information on SLURM, another resource manager, on <https://slurm.schedmd.com/quickstart.html>.
