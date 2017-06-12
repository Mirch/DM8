#pragma once

#include "../DM8/DM8.h"
using namespace DM8;
using namespace DM8::entity;
using namespace DM8::entity::component;


class SquareBehaviour : public EntityBehaviour
{
public:
	SquareBehaviour(std::string name, Entity* entity);

	void Start() override;
	void Update() override;
	

};