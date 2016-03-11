#include "getopt.h"

#include <string>

// User-supplied options container (not an OptParser part)
struct TOptions {
    // Monte-Carlo mode, enabled by default
    int MCMode;
    std::string MCModeStr;
    int Iterations;
    int IntParameter;
    bool TestMode;

    TOptions()
        : MCMode(1)
        , MCModeStr("mc")
        , Iterations(1000)
        , IntParameter(1)
        , TestMode(false)
    {
    }
    void Process() {
        MCMode = (MCModeStr == "mc") ? 1 : 0;
    }

    void Print() const {
        std::cerr << "Options:" << std::endl
            << "  Mode:           " << MCModeStr << std::endl
            << "  Iterations:     " << Iterations << std::endl
            << "  Int parameter:  " << IntParameter << std::endl
            << "  Test mode:      " << (TestMode ? "true" : "false") << std::endl
        ;
    }
};

int main(int argc, char** argv) {
    TOptions options;
    NGetOpt::TOptParser op(argc, argv);
    // Declare valid program options
    op.DeclareOption('m', "mode", "Operation mode", options.MCModeStr, std::string("mc"), "mc|data");
    op.DeclareOption('n', "iterations", "Iteration count", options.Iterations, 5000);
    op.DeclareOption('p', "int-parameter", "Some int parameter", options.IntParameter);
    op.DeclareOption('t', "test-mode", "Enable test mode", options.TestMode, true);
    op.Parse();
    options.Print();
}
