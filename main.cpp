#include "CompositeGenerator.h"
#include "DigitGenerator.h"
#include "SymbolGenerator.h"
#include "LetterGenerator.h"

int main() {
    IPasswordGenerator* generator = new CompositeGenerator(15);
    generator->add(new DigitGenerator(3));
    generator->add(new SymbolGenerator(4));
    generator->add(new LetterGenerator(5,5));

    std::string result = generator->generate();

    std::cout << result << std::endl;
    delete generator;
    return 0;
}
