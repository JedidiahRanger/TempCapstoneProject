// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TempCapstoneProjectCharacter.h"
#include "RogueCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TEMPCAPSTONEPROJECT_API ARogueCharacter : public ATempCapstoneProjectCharacter
{
	GENERATED_BODY()
	
public:
	ARogueCharacter();

	UPROPERTY(EditAnywhere)
		float DashDistance;

	UPROPERTY(EditAnywhere)
		float DashTime;

	UPROPERTY(EditAnywhere)
		float DashReset;

	void Dash();
	
	UFUNCTION(Server, Reliable)
		void Server_Dash();
protected:
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	bool m_CanDash = true;
	FVector m_InitialVel;
	float m_GroundFriction;
};