# DavOS
An Operating System that's a work in progress following the tutorial here: http://littleosbook.github.io

# Getting Started
- Clone the repo 
    ```bash
    git clone https://github.com/theProgrammerDavid/DavOS.git
    ```
- Install Bochs to run the iso
  ```bash
    sudo apt install bochs bochs-x
  ```
## Usage


- If you want to compile on your machine
    ```bash
    sudo apt-get install build-essential nasm genisoimage 
    make run
    ```
- Else, you can use docker to build the iso
  ```bash
    make docker && make run
  ```

## Docs
* [bochs config file](https://bochs.sourceforge.io/doc/docbook/user/bochsrc.html)