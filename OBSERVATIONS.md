# Observations

## Activity 1
The jitter is taken directly from from the max/min frequencies as the difference from the mean frequency. We calculate the drift using the [calc_timings.py](calc_timings.py) script with `ex_f = 20 Hz` (the expected/target frequency) and `ac_f` (the actual/measured frequency) set to the measured mean frequency.

- Scope channel 1 is the function generator
- Scope channel 2 is the Pico
- [images/function_generator.png](images/function_generator.png) is the histogram for the function generator at 20 Hz
    - Jitter: +1.7ms/-1ms
    - Drift: 18ms

### `task_delay.c`
- [images/activity_1-task_delay.png](images/activity_1-task_delay.png) is the histogram for the frequency from the Pico without a busy loop
    - Jitter: +3ms/-2.4ms
    - Drift: 18ms
- [images/activity_1-task_delay-busy_loop.png](images/activity_1-task_delay-busy_loop.png) is the histogram for the frequency from the Pico with a busy loop of 500,000 ticks.
    - Jitter: +0.5ms/-0.55ms
    - Drift: 2303.87s

### `timer.c`
- [images/activity_1-timer.png](images/activity_1-timer.png) is the histogram for the frequency from the Pico without a busy loop
    - Jitter: +2ms/-0.7ms
    - Drift: 0s
- [images/activity_1-timer-busy_loop.png](images/activity_1-timer-busy_loop.png) is the histogram for the frequency from the Pico with a busy loop of 500,000 ticks. A phase shift of 90 degrees was applied to the scope display to align the function generator to the Pico output.
    - Jitter: +2ms/-0.7ms
    - Drift: 0s

### `sleep.c`
- [images/activity_1-sleep.png](images/activity_1-sleep.png) is the histogram for the frequency from the Pico without a busy loop
    - Jitter: +1ms/-0.8ms
    - Drift: 18ms
- [images/activity_1-sleep-busy_loop.png](images/activity_1-sleep-busy_loop.png) is the histogram for the frequency from the Pico with a busy loop of 500,000 ticks
    - Jitter: +1.1ms/-0.7ms
    - Drift: 0s

## Activity 2
- Scope channel 1 is the function generator
- Scope channel 2 is the Pico
- [images/activity_2.png](images/activity_2.png) is without a busy loop
    - Delay: 1.48 us
- [images/activity_2-busy_loop.png](images/activity_2-busy_loop.png) is with a busy loop of 100,000 ticks
    - Delay: 4 .04 ms

## Activity 3
- [images/activity_3-1_task.png](images/activity_3-1_task.png) is with only a single task
- [images/activity_3-2_tasks.png](images/activity_3-2_tasks.png) is with two tasks
    - There isn't any significant change from a single task
- [images/activity_3-4_tasks.png](images/activity_3-4_tasks.png) is with four tasks
    - The frequency with four tasks is 1/3 the frequency with only one task.
