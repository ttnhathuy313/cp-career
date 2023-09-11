#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int pans = ouf.readWord("[a-z][a-z]{0,100000}", "S_i");
    
    int jans = ans.readWord("[a-z][a-z]{0,100000}", "S_i");
    
    if (pans == jans)
        quitf(_ok, "The answer is correct."); // This finishes checker with verdit OK.
    else quitf(_wa, "The answer is wrong: expected = %s, found = %s", jans, pans);
}