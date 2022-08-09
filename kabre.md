``` {}
ssh USER@kabre.cenat.ac.cr
git clone https://github.com/gpsilva2003/CRHPC2022.git
salloc -p nu -t 01:45:00
cd CRHPC2022/MPI/
module load openmpi/4.0.5
mkdir bin
make
cd bin/
mpirun -np 2 mpi_simples
``
