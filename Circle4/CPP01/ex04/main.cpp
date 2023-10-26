#include <iostream>
#include <fstream>
#include <ostream>
#include <string>


int main(int argc, char **argv)
{
    if (argc != 4 || (!argv[2] || !argv[3]))
    {
        std::cerr << "Not correct input string" << std::endl;
        return (1);
    }

    std::string     input; // 문자열 입력받을 버퍼
    std::string     output_name = std::string(argv[1]) + ".replace"; // 이름 선언
    std::ifstream   fd(argv[1]); // 파일 열기
    std::ofstream   output(output_name); // 쓰기 파일 열기
    std::string     s1 = argv[2]; // s1스트링 -> 찾는 문자열
    std::string     s2 = argv[3]; // s2스트링 -> 변경 문자열
    int             s1_len = s1.size();
    int             s2_len = s2.size();
    if (!fd.is_open() || !output.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return (1);
    }
    while (1)
    {
        std::getline(fd, input);
        size_t  index = 0;
        // while문이 2개가 존재해야지, 읽어온 문장에서 중복되는 문자열을 다 치환해줄수 있음
        while (1)
        {
            index = input.find(s1);
            // string의 find함수에서 문자열을 찾는것을 실패했을 시, size_t의 npos를 반환
            // 즉 아래의 break에 걸리게 되면 찾는 문자열이 없다는 것을 의미
            if (index == std::string::npos)
                break;
            input.erase(index, s1_len);
            input.insert(index, s2);
            index += s2_len;   
        }
        output << input;
        if (fd.eof())
            break ;
        output << std::endl;
    }
    return (0);
}

