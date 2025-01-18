﻿#pragma once
#include "animation.hpp"

Animation::Animation()
{
	currentFrame = 0;
	isPlaying = true;
	flip = false;
	loop = true;
}

void Animation::tick(float time)
{
	if (!isPlaying) return;

	currentFrame += speed * time;

	if (currentFrame >= frames.size()) {
		currentFrame -= frames.size();
		if (!loop) { isPlaying = false; return; }
	}

	int i = currentFrame;
	sprite.setTextureRect(frames[i]); // Aktualizacja klatki animacji.
	if (flip) sprite.setTextureRect(frames_flip[i]); // Ustaw odwróconą klatkę, jeśli wymaga tego stan.
}


AnimationManager::AnimationManager()
{}

AnimationManager::~AnimationManager()
{
	animList.clear(); // Usuń wszystkie animacje z pamięci.
}

void AnimationManager::loadFromXML(std::string fileName, Texture& t)
{
	TiXmlDocument animFile(fileName.c_str());

	animFile.LoadFile();

	TiXmlElement* head;
	head = animFile.FirstChildElement("sprites");

	TiXmlElement* animElement;
	animElement = head->FirstChildElement("animation");
	while (animElement)
	{
		Animation anim;
		currentAnim = animElement->Attribute("title");  // Pobierz nazwę animacji.
		int delay = atoi(animElement->Attribute("delay"));
		anim.speed = 1.0 / delay; anim.sprite.setTexture(t); // Ustaw prędkość odtwarzania animacji.

		TiXmlElement* cut;
		cut = animElement->FirstChildElement("cut");
		while (cut)
		{
			int x = atoi(cut->Attribute("x"));
			int y = atoi(cut->Attribute("y"));
			int w = atoi(cut->Attribute("w"));
			int h = atoi(cut->Attribute("h"));

			anim.frames.push_back(IntRect(x, y, w, h)); // Dodaj klatkę do animacji.
			anim.frames_flip.push_back(IntRect(x + w, y, -w, h)); // Dodaj odwróconą wersję klatki.
			cut = cut->NextSiblingElement("cut");
		}

		anim.sprite.setOrigin(0, anim.frames[0].height); // Ustaw punkt początkowy rysowania.

		animList[currentAnim] = anim;
		animElement = animElement->NextSiblingElement("animation");
	}
}

void AnimationManager::set(std::string name)
{
	currentAnim = name;
	animList[currentAnim].flip = 0;
}

void AnimationManager::draw(RenderWindow& window, int x = 0, int y = 0)
{
	animList[currentAnim].sprite.setPosition(x, y);
	window.draw(animList[currentAnim].sprite);  // Narysuj bieżącą animację w oknie.
}

void AnimationManager::flip(bool b = 1)
{
	animList[currentAnim].flip = b;
}

void AnimationManager::tick(float time)
{
	animList[currentAnim].tick(time); // Aktualizuj bieżącą animację.
}

void AnimationManager::pause()
{
	animList[currentAnim].isPlaying = false;
}

void AnimationManager::play()
{
	animList[currentAnim].isPlaying = true;
}

void AnimationManager::play(std::string name)
{
	animList[name].isPlaying = true;
}

bool AnimationManager::isPlaying()
{
	return animList[currentAnim].isPlaying;
}

float AnimationManager::getH()
{
	return animList[currentAnim].frames[0].height; // Zwróć wysokość pierwszej klatki.
}

float AnimationManager::getW()
{
	return animList[currentAnim].frames[0].width; // Zwróć szerokość pierwszej klatki.
}
