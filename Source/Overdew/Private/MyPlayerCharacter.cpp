// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"


AMyPlayerCharacter::AMyPlayerCharacter()
{
    
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArmComponent->SetupAttachment(RootComponent);
   
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComponent->SetupAttachment(SpringArmComponent);

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
    StaticMeshComponent->SetupAttachment(RootComponent);

    UCharacterMovementComponent* TempCharacterMovement = GetCharacterMovement();
    TempCharacterMovement->MaxWalkSpeed = 650.0f;
}

void AMyPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
    
    //Set base sprint speed
    UCharacterMovementComponent* TempCharacterMovement = GetCharacterMovement();
    BaseWalkSpeed = TempCharacterMovement->MaxWalkSpeed;
    SprintSpeed = TempCharacterMovement->MaxWalkSpeed * 1.5f;
    DashSpeed = SprintSpeed * 2.0f;
    BaseAcceleration = TempCharacterMovement->MaxAcceleration;
    DashAcceleration = BaseAcceleration * 2.5f;
    BaseGroundFriction = TempCharacterMovement->GroundFriction;
}

void AMyPlayerCharacter::MoveForward(float Value)
{
    if(Controller && Value != 0)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void AMyPlayerCharacter::MoveRight(float Value)
{
    if(Controller && Value != 0)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void AMyPlayerCharacter::StartSprinting()
{
    bIsSprinting = true;
    UCharacterMovementComponent* TempCharacterMovement = GetCharacterMovement();
    TempCharacterMovement->MaxWalkSpeed = SprintSpeed;
    UE_LOG(LogTemp, Warning, TEXT("Walk speed: %f"), BaseWalkSpeed);
}

void AMyPlayerCharacter::StopSprinting()
{
    bIsSprinting = false;
    UCharacterMovementComponent* TempCharacterMovement = GetCharacterMovement();
    TempCharacterMovement->MaxWalkSpeed = BaseWalkSpeed;
}

void AMyPlayerCharacter::Die()
{
}

void AMyPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    //Jump
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

    //Movement
    PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayerCharacter::MoveRight);

    //Sprint now handled in blueprint
    //PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyPlayerCharacter::StartSprinting);
    //PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyPlayerCharacter::StopSprinting);
}
