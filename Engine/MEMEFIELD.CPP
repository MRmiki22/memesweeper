#include "MemeField.h"
#include <assert.h>
#include <random>

void MemeField::Tile::SpawnMeme()
{
	assert(!hasMeme);
	hasMeme = true;
}

bool MemeField::Tile::HasMeme() const
{
	return hasMeme;
}

void MemeField::Tile::Draw(const Vei2 & screenPos, Graphics & gfx) const
{
	switch (state)
	{
	case MemeField::Tile::State::Hidden:
		break;
	case MemeField::Tile::State::Flagged:
		break;
	case MemeField::Tile::State::Revealed:
		break;
	}
}

MemeField::MemeField(int nMeme)
{
	for (int i = 0; i < nMeme; ++i)
	{
		std::random_device rd;
		std::mt19937 rng(rd());

		std::uniform_int_distribution < int > xdist(0, Wedth - 1);
		std::uniform_int_distribution < int > ydist(0, Height - 1);

		Vei2 memePos;
		do
		{
			memePos = { xdist(rng), ydist(rng) };

		} while (TileAt(memePos).HasMeme());
		TileAt(memePos).SpawnMeme();
	}
}

void MemeField::Draw(Graphics & gfx) const
{
}

RectI MemeField::Getrect() const
{
	return RectI(0, Wedth, 0, Height);
}

MemeField::Tile & MemeField::TileAt(const Vei2 & gridPos)
{
	return Field[gridPos.y * Wedth + gridPos.x];
}

const MemeField::Tile & MemeField::TileAt(const Vei2 & gridPos) const
{
	return Field[gridPos.y * Wedth + gridPos.x];
}
