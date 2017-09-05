// Fill out your copyright notice in the Description page of Project Settings.

#include "BazookaBullet.h"


void ABazookaBullet::BeginPlay() {
	Super::BeginPlay();

	Damage = FMath::RandRange(10, 30);
}



