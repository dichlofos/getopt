NGetOpt::OptParser
==================

Simple C++ command line arguments interperter written in pure plain old C++
without stupid lambdas, variadic templates and other modern C++ bullshit.

As easy as this:

    NGetOpt::TOptParser op(argc, argv);

    // Declare valid program options
    std::string mode;
    op.DeclareOption('m', "mode", "Operation mode", mode, std::string("mc"), "mc|data");

    int iterations;
    op.DeclareOption('n', "iterations", "Iteration count", iterations, 5000);

    // Without default value
    op.DeclareOption('p', "int-parameter", "Some int parameter", options.IntParameter);

    // Bool option (without value)
    op.DeclareOption('t', "test-mode", "Enable test mode", options.TestMode, true);

    // Parse options
    op.Parse();
