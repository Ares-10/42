#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n=== Form 생성 및 상태 출력 테스트 ===" << std::endl;
	try {
		Form basic;
		Form grades(50, 30);
		Form named("Tax Form", 90, 70);
		Form copied(named);

		std::cout << "basic: " << &basic << std::endl;
		std::cout << "grades: " << &grades << std::endl;
		std::cout << "named: " << &named << std::endl;
		std::cout << "copied: " << &copied << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "예외 발생: " << e.what() << std::endl;
	}

	std::cout << "\n=== Form 서명 테스트 ===" << std::endl;
	try {
		Form contract("Contract", 75, 50);
		Bureaucrat high("Director", 1);
		Bureaucrat low("Intern", 150);

		std::cout << "서명 전 상태: " << &contract << std::endl;
		high.signForm(contract);
		// contract.beSigned(high);
		std::cout << "높은 등급 관료 서명 후: " << &contract << std::endl;

		Form contract2("Contract2", 75, 50);
		low.signForm(contract);
		// contract2.beSigned(low);
	}
	catch (std::exception &e) {
		std::cout << "예외 발생: " << e.what() << std::endl;
	}

	std::cout << "\n=== 잘못된 등급으로 Form 생성 시도 ===" << std::endl;
	try {
		Form invalid("Invalid", 151, 50);
	}
	catch (std::exception &e) {
		std::cout << "예외 발생: " << e.what() << std::endl;
	}
	try {
		Form invalid2("Invalid2", 50, 0);
	}
	catch (std::exception &e) {
		std::cout << "예외 발생: " << e.what() << std::endl;
	}
}