// Fill out your copyright notice in the Description page of Project Settings.

#include "EliteMonster.h"
#include "Personagem.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"
#include "Enemy.h"




void AEliteMonster::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse,
	const FHitResult & Hit) {

	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
        UE_LOG(LogTemp, Warning, TEXT("PASSOU DE FASE!!!"));
		Destroy();
	}
}




