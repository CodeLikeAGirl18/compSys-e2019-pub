long p(long *args, long disp) {
    long* start = args;
    while (*args > 0) {
        *args += disp;
        args++;
    }
    return args-start;
}
