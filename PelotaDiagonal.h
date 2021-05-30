#pragma once
#include "Pelota.h"
class PelotaDiagonal :
    public Pelota
{
public:
    PelotaDiagonal();
    PelotaDiagonal(float vel);
    void mover() override;
};

