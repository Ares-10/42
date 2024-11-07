#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n=== 관료 생성 테스트 ===" << std::endl;
    try {
        Bureaucrat president("President", 1);      // 최고 등급
        Bureaucrat manager("Manager", 70);         // 중간 등급
        Bureaucrat intern("Intern", 150);          // 최저 등급

        std::cout << &president << std::endl;
        std::cout << &manager << std::endl;
        std::cout << &intern << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "예외 발생: " << e.what() << std::endl;
    }

    std::cout << "\n=== ShrubberyCreationForm 테스트 ===" << std::endl;
    try {
        Bureaucrat gardener("Gardener", 130);     // 서명 가능, 실행 불가능
        Bureaucrat chief("Chief", 1);             // 모두 가능
        ShrubberyCreationForm shrub("garden");

        std::cout << "양식 정보:" << std::endl;
        std::cout << &shrub << std::endl;

        // 낮은 등급 관료가 서명 시도
        std::cout << "\n낮은 등급 관료의 서명 시도:" << std::endl;
        shrub.beSigned(gardener);
        std::cout << &shrub << std::endl;

        // 낮은 등급 관료가 실행 시도
        std::cout << "\n낮은 등급 관료의 실행 시도:" << std::endl;
        shrub.execute(gardener);
    }
    catch (std::exception &e) {
        std::cout << "예외 발생: " << e.what() << std::endl;
    }

    std::cout << "\n=== RobotomyRequestForm 테스트 ===" << std::endl;
    try {
        Bureaucrat engineer("Engineer", 40);      // 서명 및 실행 가능
        Bureaucrat assistant("Assistant", 80);    // 서명만 가능
        RobotomyRequestForm robot("Bender");

        std::cout << "양식 정보:" << std::endl;
        std::cout << &robot << std::endl;

        // 서명
        std::cout << "\n서명 후 상태:" << std::endl;
        robot.beSigned(engineer);
        std::cout << &robot << std::endl;

        // 여러 번 실행하여 50% 확률 테스트
        std::cout << "\n로봇화 시도 (3번):" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << "\n" << i + 1 << "번째 시도:" << std::endl;
            robot.execute(engineer);
        }
    }
    catch (std::exception &e) {
        std::cout << "예외 발생: " << e.what() << std::endl;
    }

    std::cout << "\n=== PresidentialPardonForm 테스트 ===" << std::endl;
    try {
        Bureaucrat president("President", 1);     // 모두 가능
        Bureaucrat director("Director", 20);      // 서명만 가능
        PresidentialPardonForm pardon("Criminal");

        std::cout << "양식 정보:" << std::endl;
        std::cout << &pardon << std::endl;

        // 서명 없이 실행 시도
        std::cout << "\n서명 없이 실행 시도:" << std::endl;
        pardon.execute(president);
    }
    catch (std::exception &e) {
        std::cout << "예외 발생: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrat::executeForm 테스트 ===" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1);
        ShrubberyCreationForm shrub("park");
        RobotomyRequestForm robot("C3PO");
        PresidentialPardonForm pardon("Prisoner");

        // 모든 양식에 서명
        shrub.beSigned(ceo);
        robot.beSigned(ceo);
        pardon.beSigned(ceo);

        // executeForm 메서드를 통한 실행
        std::cout << "\n각 양식 실행:" << std::endl;
        ceo.executeForm(shrub);
        ceo.executeForm(robot);
        ceo.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "예외 발생: " << e.what() << std::endl;
    }
}