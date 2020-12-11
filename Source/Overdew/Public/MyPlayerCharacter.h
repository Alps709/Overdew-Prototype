// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "MyPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class OVERDEW_API AMyPlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AMyPlayerCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Player")
	UStaticMeshComponent* StaticMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable, Category="Movement")
    void StartSprinting();
	UFUNCTION(BlueprintCallable, Category="Movement")
    void StopSprinting();

    virtual void Die() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Save the walk speed of the movement component so it can be set back after sprinting
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Movement")
	float BaseWalkSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Movement")
	float SprintSpeed;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Movement")
	bool bIsSprinting;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Movement")
	float DashSpeed;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Movement")
	float BaseAcceleration;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Movement")
	float DashAcceleration;
	
};
