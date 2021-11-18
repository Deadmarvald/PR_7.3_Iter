#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3Iter/Lab_07_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT73Iter
{
	TEST_CLASS(UT73Iter)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int t;

			int** a = new int* [2];
			for (int i = 0; i < 2; i++)
				a[i] = new int[2];

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					a[i][j] = 0;
				}
			}

			t = FindRow(a, 2, 2);

			Assert::AreEqual(t, 1);
		}
	};
}