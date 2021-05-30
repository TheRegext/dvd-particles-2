#pragma once
#include "Pelota.h"
class PelotaHorizontal :
    public Pelota
{
public:
    PelotaHorizontal();
    void mover() override;
};

