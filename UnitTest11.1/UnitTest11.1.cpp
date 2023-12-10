#include "pch.h"
#include "CppUnitTest.h"
#include "../Project11.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* testInput = "123abc456xyz789";
			const char* expectedOutput = "abcxyz";

			// Create a temporary input file
			std::ofstream inputFile("test_input.bin", std::ios::binary);
			inputFile.write(testInput, strlen(testInput));
			inputFile.close();

			// Act
			ProcessBIN1("test_input.bin", "test_output.bin");

			// Assert
			std::ifstream outputFile("test_output.bin", std::ios::binary);
			std::ostringstream outputStream;
			outputStream << outputFile.rdbuf();
			outputFile.close();

			Assert::AreEqual(expectedOutput, outputStream.str().c_str());
		}
	};
}
