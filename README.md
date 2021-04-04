# DavOS
An Operating System that's a work in progress following the tutorial here: http://littleosbook.github.io

# Getting Started
- Clone the repo 
    ```bash
    git clone https://github.com/theProgrammerDavid/DavOS.git
    ```
## Usage


- If you want to compile on your machine
    ```bash
    sudo apt-get install build-essential nasm genisoimage bochs bochs-sdl
    make run
    ```
- Else, you can use docker to build the iso
  ```bash
    make docker && make run
  ```

