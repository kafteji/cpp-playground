load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "lib",
    hdrs = glob(["include/**/*.hpp"]),
    includes = ["include"],
)

cc_binary(
    name = "playground",
    srcs = glob(["tests/**/*.cpp"]),
    deps = [
        ":lib",
        "@google_googletest//:gtest_main",
    ],
)
