#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n=== 모든 가능한 양식 생성 테스트 ===" << std::endl;
    {
        Intern intern;
        AForm *form1 = intern.makeForm("PresidentialPardonForm", "Criminal");
        AForm *form2 = intern.makeForm("RobotomyRequestForm", "Bender");
        AForm *form3 = intern.makeForm("ShrubberyCreationForm", "Garden");

        // 각 폼이 제대로 생성되었는지 확인
        std::cout << "\n생성된 양식들 정보:" << std::endl;
        if (form1)
            std::cout << form1 << std::endl;
        if (form2)
            std::cout << form2 << std::endl;
        if (form3)
            std::cout << form3 << std::endl;

        // 생성된 폼으로 실제 작업 수행
        std::cout << "\n생성된 양식으로 작업 수행:" << std::endl;
        try {
            Bureaucrat boss("Boss", 1);
            if (form1) {
                form1->beSigned(boss);
                form1->execute(boss);
            }
            if (form2) {
                form2->beSigned(boss);
                form2->execute(boss);
            }
            if (form3) {
                form3->beSigned(boss);
                form3->execute(boss);
            }
        }
        catch (std::exception &e) {
            std::cout << "예외 발생: " << e.what() << std::endl;
        }

        delete form1;
        delete form2;
        delete form3;
    }

    std::cout << "\n=== 존재하지 않는 양식 생성 시도 ===" << std::endl;
    {
        Intern intern;
        AForm *invalid_form = intern.makeForm("InvalidForm", "Target");

        if (invalid_form == NULL)
            std::cout << "존재하지 않는 양식은 NULL을 반환함" << std::endl;
        else
            delete invalid_form;
    }

    std::cout << "\n=== 여러 인턴이 같은 양식 생성 ===" << std::endl;
    {
        Intern intern1;
        Intern intern2;

        AForm *form1 = intern1.makeForm("RobotomyRequestForm", "Robot1");
        AForm *form2 = intern2.makeForm("RobotomyRequestForm", "Robot2");

        if (form1 && form2) {
            std::cout << "\n첫 번째 인턴이 생성한 양식:" << std::endl;
            std::cout << form1 << std::endl;
            std::cout << "\n두 번째 인턴이 생성한 양식:" << std::endl;
            std::cout << form2 << std::endl;
        }

        delete form1;
        delete form2;
    }
}