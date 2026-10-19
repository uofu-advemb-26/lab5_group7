# This is the main binary. List your C files here.
add_executable(hello_freertos
    hello_freertos.c
    )

pico_set_program_name(hello_freertos "test")
pico_set_program_version(hello_freertos "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(hello_freertos 1)
pico_enable_stdio_usb(hello_freertos 0)

# Add the libraries to the build
target_link_libraries(hello_freertos PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(hello_freertos PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(hello_freertos)

find_program(OPENOCD openocd)
find_program(PICOTOOL picotool)

add_custom_target(flash ${PICOTOOL} load -f $<TARGET_FILE:hello_freertos> DEPENDS hello_freertos)
add_custom_target(openocd_flash ${OPENOCD} -s ${OPENOCD_PATH} -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c 'adapter speed 5000' -c program "$<TARGET_FILE:hello_freertos>" verify reset exit' DEPENDS hello_freertos)

# This is the main binary. List your C files here.
add_executable(timer
    timer.c
    )

pico_set_program_name(timer "test")
pico_set_program_version(timer "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(timer 1)
pico_enable_stdio_usb(timer 0)

# Add the libraries to the build
target_link_libraries(timer PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(timer PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(timer)

find_program(OPENOCD openocd)
find_program(PICOTOOL picotool)

add_custom_target(flash_timer ${PICOTOOL} load -f $<TARGET_FILE:timer> DEPENDS timer)
add_custom_target(openocd_flash_timer ${OPENOCD} -s ${OPENOCD_PATH} -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c 'adapter speed 5000' -c program "$<TARGET_FILE:timer>" verify reset exit' DEPENDS timer)


# This is the main binary. List your C files here.
add_executable(rtc
    rtc.c
    )

pico_set_program_name(rtc "test")
pico_set_program_version(rtc "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(rtc 1)
pico_enable_stdio_usb(rtc 0)

# Add the libraries to the build
target_link_libraries(rtc PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(rtc PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(rtc)

find_program(OPENOCD openocd)
find_program(PICOTOOL picotool)

add_custom_target(flash_rtc ${PICOTOOL} load -f $<TARGET_FILE:rtc> DEPENDS rtc)
add_custom_target(openocd_flash_rtc ${OPENOCD} -s ${OPENOCD_PATH} -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c 'adapter speed 5000' -c program "$<TARGET_FILE:rtc>" verify reset exit' DEPENDS rtc)

# This is the main binary. List your C files here.
add_executable(sleep
    sleep.c
    )

pico_set_program_name(sleep "test")
pico_set_program_version(sleep "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(sleep 1)
pico_enable_stdio_usb(sleep 0)

# Add the libraries to the build
target_link_libraries(sleep PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(sleep PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(sleep)

find_program(OPENOCD openocd)
find_program(PICOTOOL picotool)

add_custom_target(flash_sleep ${PICOTOOL} load -f $<TARGET_FILE:sleep> DEPENDS sleep)
add_custom_target(openocd_flash_sleep ${OPENOCD} -s ${OPENOCD_PATH} -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c 'adapter speed 5000' -c program "$<TARGET_FILE:sleep>" verify reset exit' DEPENDS sleep)

# This is the main binary. List your C files here.
add_executable(task_delay
    task_delay.c
    )

pico_set_program_name(task_delay "test")
pico_set_program_version(task_delay "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(task_delay 1)
pico_enable_stdio_usb(task_delay 0)

# Add the libraries to the build
target_link_libraries(task_delay PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(task_delay PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(task_delay)

find_program(OPENOCD openocd)
find_program(PICOTOOL picotool)

add_custom_target(flash_task_delay ${PICOTOOL} load -f $<TARGET_FILE:task_delay> DEPENDS task_delay)
add_custom_target(openocd_flash_task_delay ${OPENOCD} -s ${OPENOCD_PATH} -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c 'adapter speed 5000' -c program "$<TARGET_FILE:task_delay>" verify reset exit' DEPENDS task_delay)

# This is the main binary. List your C files here.
add_executable(gpio_interrupt
    gpio_interrupt.c
    )

pico_set_program_name(gpio_interrupt "test")
pico_set_program_version(gpio_interrupt "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(gpio_interrupt 1)
pico_enable_stdio_usb(gpio_interrupt 0)

# Add the libraries to the build
target_link_libraries(gpio_interrupt PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(gpio_interrupt PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(gpio_interrupt)

find_program(OPENOCD openocd)
find_program(PICOTOOL picotool)

add_custom_target(flash_gpio_interrupt ${PICOTOOL} load -f $<TARGET_FILE:gpio_interrupt> DEPENDS gpio_interrupt)
add_custom_target(openocd_flash_gpio_interrupt ${OPENOCD} -s ${OPENOCD_PATH} -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c 'adapter speed 5000' -c program "$<TARGET_FILE:gpio_interrupt>" verify reset exit' DEPENDS gpio_interrupt)

