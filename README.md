# Build procedure

## Initial steps (only once)

```bash
git clone --recursive https://github.com/espressif/esp-idf
cd esp-idf
./tools/idf_tools.py install-python-env
./install.sh
```
The command before last installs a virtual python environment `~/.espressif/python_env`.
The last command downloads tons of tools (including toolchain) in the `~/.espressif` directory.

## Everyday initial steps (once per programming session)

```bash
source /path/to/esp-idf/export.sh
```

## Useful commands
```bash
idf.py build # budild
idf.py -p PORT flash # flash
idf.py -p PORT monitor # serial monitor, you can also use a standard terminal like minicom
```

# Notes

Standalone toolchain: https://github.com/espressif/crosstool-NG/releases/download/esp-12.2.0_20230208/xtensa-esp32-elf-12.2.0_20230208-x86_64-linux-gnu.tar.xz


### Build with API written in `asm#`

Build the sources written in `asm#` (https://github.com/djolertrk/proto-switch-asmsharp-components?tab=readme-ov-file#build):
```
git clone https://github.com/djolertrk/proto-switch-asmsharp-components.git
mkdir build && cd build
cmake .. -G Ninja -DASMSHARP_COMPILER=/home/djtodorovic/projects/LL-project/build_asm_sharp_debug/bin/asm-sharp -DASMSHARP_CC_COMPILER=/home/djtodorovic/projects/LLVM/build_debugrel/bin/clang
ninja
[1/1] Generating libprint.a
ar: creating libprint.a 
```

Build the app (just rename the path):
```
mkdir && cd build
cmake ../ -G Ninja -Wno-dev -DASMSHARP_COMPONENTS=/home/djtodorovic/projects/private/ESP32/proto-switch-asmsharp-components/build  && ninja
...
[1/1] cd /home/djtodorovic/projects/private/ESP32/proto-switch-din/build/bootloader/esp-idf/esptool_py && python /home/djtodorovic/projects/private/ESP32/esp-idf/components/partition_table/check_sizes.py --offset 0x8000 bootloader 0x0 /home/djtodorovic/projects/private/ESP32/proto-switch-din/build/bootloader/bootloader.bin
Bootloader binary size 0x5170 bytes. 0x2e90 bytes (36%) free.
[6/7] Generating binary image from built executable
esptool.py v4.7.0
Creating esp32c3 image...
Merged 2 ELF sections
Successfully created esp32c3 image.
Generated /home/djtodorovic/projects/private/ESP32/proto-switch-din/build/proto_switch_din.bin
[7/7] cd /home/djtodorovic/projects/private/ESP32/proto-switch-din/build/esp-idf/esptool_py && python /home/djtodorovic/projects/private...witch-din/build/partition_table/partition-table.bin /home/djtodorovic/projects/private/ESP32/proto-switch-din/build/proto_switch_din.bin
proto_switch_din.bin binary size 0x2c590 bytes. Smallest app partition is 0x100000 bytes. 0xd3a70 bytes (83%) free.
```
