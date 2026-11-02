def calc_timing(ex_f:Number, ac_f:Number, max_f:Number, min_f:Number, drift_period:Number):
    '''
    @param ex_f: Expected frequency (in Hz)
    @param ac_f: Actual frequency (in Hz)
    @param max_f: Max acutal frequency (in Hz)
    @param min_f: Min acutal frequency (in Hz)
    @param drift_period: Period to calculate the drift (in seconds)
    '''
    # Calculate jitter time
    print(f"jitter = +{max_f - ac_f:g} s / -{ac_f - min_f:g} s")

    # Calculate drift time
    # The expected number of cycles in the drift period
    ex_cycles = ex_f*drift_period
    print(f"expected_cycles = {ex_cycles:g} cycles")

    # The timing drift during the drift period
    drift = abs(ex_cycles*(ex_f**-1 - ac_f**-1))
    print(f"drift = {drift:g} seconds")
    print()


def print_header(header:String):
    print("------------------------------")
    print(header)
    print("------------------------------")


def main():
    DRIFT_PERIOD = 60**2        # Calculate drift over 1 hour

    print("Function Generator")
    calc_timing(20, 19.9999, 20.0016, 19.9989, DRIFT_PERIOD)

    print()
    print_header("Activity 1: task_delay.c")
    print("Without busy loop")
    calc_timing(20, 20.0001, 20.0031, 19.9977, DRIFT_PERIOD)

    print("With busy loop")
    calc_timing(20, 12.1954, 12.1959, 12.1949, DRIFT_PERIOD)

    print()
    print_header("Activity 1: timer.c")
    print("Without busy loop")
    calc_timing(20, 20, 20.0020, 19.9993, DRIFT_PERIOD)

    print("With busy loop")
    calc_timing(20, 20, 20.0020, 19.9993, DRIFT_PERIOD)

    print()
    print_header("Activity 1: sleep.c")
    print("Without busy loop")
    calc_timing(20, 20.0001, 20.0011, 19.9993, DRIFT_PERIOD)

    print("With busy loop")
    calc_timing(20, 20, 20.0011, 19.9993, DRIFT_PERIOD)


if (__name__ == "__main__"):
    main()
