import os

# toolchains options
ARCH        ='risc-v'
CPU         ='e9xx'
CROSS_TOOL  ='gcc'

if os.getenv('RTT_ROOT'):
    RTT_ROOT = os.getenv('RTT_ROOT')
else:
    RTT_ROOT = r'../../..'


if os.getenv('RTT_CC'):
    CROSS_TOOL = os.getenv('RTT_CC')

if  CROSS_TOOL == 'gcc':
    PLATFORM    = 'gcc'
    EXEC_PATH   = ''
else:
    print('Please make sure your toolchains is GNU GCC!')
    exit(0)

if os.getenv('RTT_EXEC_PATH'):
    EXEC_PATH = os.getenv('RTT_EXEC_PATH')

BUILD = 'debug'

if PLATFORM == 'gcc':
    # toolchains
    PREFIX  = 'riscv64-unknown-elf-'
    CC      = PREFIX + 'gcc'
    CXX     = PREFIX + 'g++'
    AS      = PREFIX + 'gcc'
    AR      = PREFIX + 'ar'
    LINK    = PREFIX + 'gcc'
    TARGET_EXT = 'elf'
    SIZE    = PREFIX + 'size'
    OBJDUMP = PREFIX + 'objdump'
    OBJCPY  = PREFIX + 'objcopy'

    DEVICE  = ' -march=rv32imafcpzpsfoperand_xtheade -mabi=ilp32f -mtune=e907'
    CFLAGS  = DEVICE + f' -DRT_USING_LEGACY -std=gnu99 -fno-jump-tables -fno-common -fms-extensions -ffunction-sections -fdata-sections -fmessage-length=0 -Wall -Wchar-subscripts -Wformat -Wundef -Wuninitialized -Winit-self -Wignored-qualifiers -I {RTT_ROOT}\\components\\legacy -I {RTT_ROOT}\\components\\legacy\\dfs -I {RTT_ROOT}\\components\\dfs\\include\\ -I {RTT_ROOT}\\components\\dfs\\filesystems\\elmfat\\ -I {RTT_ROOT}\\components\\dfs\\filesystems\\romfs -I {RTT_ROOT}\\applications -I {RTT_ROOT}\\bsp\\bouffalo_lab\\bl61x\\applications\\lib\\mavlink\\v2.0\\fmt -I {RTT_ROOT}\\components/utilities/ulog -I {RTT_ROOT}\\bsp\\bouffalo_lab\\libraries\\bl_mcu_sdk\\drivers\\lhal\\include\\arch\\risc-v\\t-head\\csi_dsp\\include -w'
    CFLAGS += ' -fstrict-volatile-bitfields -fshort-enums -Wno-error=unused-variable -Wno-error=format= -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=deprecated-declarations -Wno-format'
    LINKER_SCRIPTS = r'board/linker_scripts/bl616_flash.ld'

    AFLAGS  = ' -c' + DEVICE + ' -x assembler-with-cpp'
    LFLAGS  = DEVICE + ' -nostartfiles -ufw_header -fms-extensions -ffunction-sections -fdata-sections -Wl,--gc-sections,-Map=rtthread.map,-cref,-u,_start -T ' + LINKER_SCRIPTS
    CPATH   = ''
    LPATH   = ''

    if BUILD == 'debug':
        CFLAGS += ' -O0 -g3'
        AFLAGS += ' -g3'
    else:
        CFLAGS += ' -O3'

    CXXFLAGS = CFLAGS + ' -std=gnu++17 -Wno-multichar'

DUMP_ACTION = OBJDUMP + ' -D -S $TARGET > rtt.asm\n'
POST_ACTION = OBJCPY + ' -O binary $TARGET rtthread.bin\n' + SIZE + ' $TARGET \n'
POST_ACTION += 'sh combine.sh bl616 ./rtthread.bin\n'