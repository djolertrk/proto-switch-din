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
