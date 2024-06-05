//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_TENOR_H
#define LABS_KREDIT_MOTOR_TENOR_H


class Tenor {
public:
    Tenor(const int& month, const int& percentageInterest);
    const int& getMonth() const;
    const int& getPercentageInterest() const;
private:
    int month;
    int percentageInterest;
};


#endif //LABS_KREDIT_MOTOR_TENOR_H
