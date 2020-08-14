#pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "RectI.h"
class MemeField
{
private:
	class Tile
	{
	public:
		enum class State
		{
			Hidden,
			Flagged,
			Revealed,
		};
		void SpawnMeme();
		bool HasMeme() const;
		void Draw(const Vei2& screenPos, Graphics& gfx) const;
	private:
		bool hasMeme = false;
		State state = State::Hidden;
	};
public:
	MemeField(int nMeme);
	void Draw(Graphics& gfx) const;
	RectI Getrect() const;
private:
	Tile& TileAt(const Vei2& gridPos);
	const Tile& TileAt(const Vei2& gridPos) const;
private:
	static constexpr int Wedth = 20;
	static constexpr int Height = 16;
	Tile Field[Wedth * Height];
};