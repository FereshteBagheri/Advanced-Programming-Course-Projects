#pragma once
#ifndef BULLET_HPP
#define BULLET_HPP
#include "rsdl.hpp"
#include "define.hpp"
#include "object.hpp"

using namespace std;

class Bullet : public Object
{
public:
  virtual void move(string direction);

};
#endif