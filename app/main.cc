#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

#include "lib.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"

using namespace std;

static void initLogger(void) {
    spdlog::set_level(spdlog::level::trace);
    // auto sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(path, size, rotate, true);
    // sink->should_log(spdlog::level::trace);
    // spdlog::default_logger()->sinks().push_back(sink);
    // spdlog::default_logger()->flush_on(spdlog::level::trace);
}

int main(int argc, char *argv[]) {
    initLogger();
    SPDLOG_INFO("Hello, world");

    return 0;
}
