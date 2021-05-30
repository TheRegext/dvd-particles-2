#pragma once
#include "Pelota.h"
class PelotaVertical :
    public Pelota
{
public:
    PelotaVertical();
    void mover() override;
};

