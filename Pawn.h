#pragma once
class Pawn
{
	private:

	public:
		void drawGeometry(float scale, float x, float y, float z);
		void drawBase(float scale, float x, float y, float z);
		void drawBody(float scale, float x, float y, float z);
		void animatePiece(bool colour, int pieceNum);
};

