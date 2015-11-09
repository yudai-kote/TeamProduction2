#pragma once
#include "../../Classbase.h"
#include "../../Share/Share.h"

//share‚É’Ç‰Á‚·‚é•ª



//



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