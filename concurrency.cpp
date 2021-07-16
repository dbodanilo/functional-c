
std::atomic x = false;

// thread one
x.store(true, std::memory_order_release);

// thread two
x.load(std::memory_order_acquire);
