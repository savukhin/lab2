#ifndef DELTOIDA_CPP
#define DELTOIDA_CPP

class Deltoid {
private:
    float R;
    float r;
public:
    Deltoid(float r) {
        this->r = r;
        this->R = 3 * r;
    }

    float LenWithTangent() {
        return 4 * R / 3;
    }

    float Len() {
        return 16 * this->R / 3;
    }

    float Square() {
        return 2 * M_PI * this->R * this->R / 9;
    }

    std::pair<float, float> Parameter(float t) {
        float x = 2 * this->r * cos(t) + this->r * cos(2*t);
        float y = 2 * this->r * sin(t) - this->r * sin(2*t);
        return std::pair<float, float>(x, y);
    }

    char* GetEqualation() {
        std::string answer = "";
        answer = "(x^2 + y^2)^2 + " 
            + std::to_string(8 * r) + "x(x^2 - 3y^2) + "
            + std::to_string(18 * r * r) + "(x^2+y^2) = "
            + std::to_string(27 * r * r * r * r);

        char* res = new char[answer.length() + 1];
        strcpy(res, answer.c_str());
        return res;
    }

    std::string ToString() {
        std::string answer = "";
        answer += "Smaller round radius: " + std::to_string(this->r) + '\n';
        answer += "Bigger round radius: " + std::to_string(this->R) + '\n';
        return answer;
    }
};

#endif