// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class OVERDEW_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Combat")
	virtual void Die();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	//Base stats that every character in the game should have

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Stats")
	float Health;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Stats")
	float Stamina;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Combat")
	bool bCanBeStunned;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Combat")
	bool bIsStunned;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Combat")
	bool bCanBeKnockedBack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Combat")
	bool bIsDead;
};
