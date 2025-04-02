sudo dnf install git autoconf automake python3 gmp-devel mpfr-devel texinfo zlib-devel
git clone --depth 1 --recursive https://github.com/riscv-collab/riscv-gnu-toolchain
cd riscv-gnu-toolchain
git submodule update --init --recursive
./configure --prefix=~/riscv --enable-multilib
make -j linux
