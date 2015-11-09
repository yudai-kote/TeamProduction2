#pragma once
#include "../../Classbase.h"
#include "../../Share/Share.h"

enum Maptype
{
	LOAD,
	NONE
};

class Block : public Classbase
{
private:

	Maptype map_type;

public:

	Block();

	const Maptype Getmaptype();
	const void Setmaptype(int);

	void Setup();
	void Update();
	void Draw();


};