// Unit-тест до завдання 6.2 (рекурсивний спосіб). Варіант 20
// Функція обчислює середнє арифметичне індексів парних елементів.
#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr6.2 _rec/Pr6.2_rec.cpp"      // шлях і назву файлу змініть на свої

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62_rec
{
	TEST_CLASS(UnitTest62_rec)
	{
	public:

		TEST_METHOD(TestAverage)
		{
			// парні елементи на індексах 1, 3, 5 -> (1 + 3 + 5) / 3 = 3
			int a[6] = { 1, 2, 3, 4, 5, 6 };
			double t = AverageIndexEven(a, 6, 0, 0, 0);
			Assert::AreEqual(3.0, t, 1e-9);
		}

		TEST_METHOD(TestAverageNegativeAndZero)
		{
			// -4, 0, -2 - парні, індекси 0, 2, 4 -> 6 / 3 = 2
			int a[5] = { -4, 1, 0, 3, -2 };
			double t = AverageIndexEven(a, 5, 0, 0, 0);
			Assert::AreEqual(2.0, t, 1e-9);
		}

		TEST_METHOD(TestAverageFraction)
		{
			// парні на індексах 0, 1, 3 -> 4 / 3
			int a[4] = { 2, 4, 1, 6 };
			double t = AverageIndexEven(a, 4, 0, 0, 0);
			Assert::AreEqual(4.0 / 3.0, t, 1e-9);
		}

		TEST_METHOD(TestNoEven)
		{
			// парних елементів немає - функція повертає 0
			int a[4] = { 1, 3, -5, 7 };
			double t = AverageIndexEven(a, 4, 0, 0, 0);
			Assert::AreEqual(0.0, t, 1e-9);
		}
	};
}