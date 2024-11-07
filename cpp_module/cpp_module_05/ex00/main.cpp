#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n=== 생성자 테스트 ===" << std::endl;

	Bureaucrat a;
	Bureaucrat b("Bob");
	Bureaucrat c(75);
	Bureaucrat d("Charlie", 100);
	Bureaucrat e(d);

	std::cout << "a: " << &a << std::endl;
	std::cout << "b: " << &b << std::endl;
	std::cout << "c: " << &c << std::endl;
	std::cout << "d: " << &d << std::endl;
	std::cout << "e: " << &e << std::endl;

	std::cout << "\n=== 등급 증가/감소 테스트 ===" << std::endl;
	try {
		Bureaucrat worker("Worker", 75);
		std::cout << "초기 상태: " << &worker << std::endl;

		worker.incrementGrade();
		std::cout << "등급 증가 후: " << &worker << std::endl;

		worker.decrementGrade();
		std::cout << "등급 감소 후: " << &worker << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "예외 발생: " << e.what() << std::endl;
	}

	std::cout << "\n=== 최고 등급 예외 테스트 ===" << std::endl;
	try {
		Bureaucrat highRank("HighRank", 1);
		std::cout << "현재 상태: " << &highRank << std::endl;
		highRank.incrementGrade(); // 1보다 높은 등급으로 올라가려 시도
	}
	catch (std::exception &e) {
		std::cout << "예외 발생: " << e.what() << std::endl;
	}

	std::cout << "\n=== 최저 등급 예외 테스트 ===" << std::endl;
	try {
		Bureaucrat lowRank("LowRank", 150);
		std::cout << "현재 상태: " << &lowRank << std::endl;
		lowRank.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << "예외 발생: " << e.what() << std::endl;
	}

	std::cout << "\n=== 잘못된 등급으로 생성 시도 테스트 ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
	}
	catch (std::exception &e) {
		std::cout << "예외 발생: " << e.what() << std::endl;
	}

	std::cout << "\n=== 대입 연산자 테스트 ===" << std::endl;
	try {
		Bureaucrat a("Original", 50);
		Bureaucrat b("Target", 100);

		std::cout << "대입 전 a: " << &a << std::endl;
		std::cout << "대입 전 b: " << &b << std::endl;

		b = a;
		std::cout << "대입 후 b: " << &b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "예외 발생: " << e.what() << std::endl;
	}
}
