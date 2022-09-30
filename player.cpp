#include "DxLib.h"
#include <cassert>
#include "game.h"
#include "player.h"

namespace
{
	//�L�����N�^�[�A�j���[�V����1�R�}������̃t���[����
	constexpr int kAnimeChangeFrame = 8;

}

Player::Player()
{
	for (auto& handle : m_handle) {
		handle = -1;
	}
}

Player::~Player()
{
	
}

void Player::init()
{
	m_pos.x = Game::kScreenWidth / 2 - kGraphicSizeX / 2;
	m_pos.y = Game::kScreenHeight / 2 - kGraphicSizeY / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_animeDirections = 0;

}

void Player::update()
{
	
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", m_animeFrame);

	// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isKey = false;
	if (padState & PAD_INPUT_UP)
	{
		//��@73�`96
		m_animeDirections = 3;
		isKey = true;
	}
	if (padState & PAD_INPUT_DOWN)
	{
		//���@1�`24
		m_animeDirections = 0;
		isKey = true;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		//���@25�`48
		m_animeDirections = 1;
		isKey = true;
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		//�E�@49�`72 
		m_animeDirections = 2;
		isKey = true;
	}

	//�L�����N�^�[�̃A�j���[�V����
	if(isKey) m_animeFrame++;

	if (m_animeFrame >= kGraphicDivX * kAnimeChangeFrame) {
		m_animeFrame = 0;
	}

	int tempAnimeNo = m_animeFrame / kAnimeChangeFrame;
	m_animeNo = m_animeDirections * kGraphicDivX + tempAnimeNo;
}

void Player::draw()
{
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
}