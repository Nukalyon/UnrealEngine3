// Fill out your copyright notice in the Description page of Project Settings.


#include "Slot_Machine.h"

#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASlot_Machine::ASlot_Machine()
{
 	PrimaryActorTick.bCanEverTick = true;
	// Création de l'élément qui va devenir la racine
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	
	// Création arborescence
	Cube = CreateDefaultSubobject<UStaticMeshComponent>("Cube");	
	Cube -> SetupAttachment(Root);
	Reels = CreateDefaultSubobject<USceneComponent>("Bobines");
	Reels->SetupAttachment(Root);
	Levier = CreateDefaultSubobject<USceneComponent>("Levier");
	Levier->SetupAttachment(Root);
	Ligne = CreateDefaultSubobject<UStaticMeshComponent>("Ligne");
	Ligne->SetupAttachment(Root);
	Speaker = CreateDefaultSubobject<UAudioComponent>("Speaker");
	Speaker->SetupAttachment(Root);
	Confetti = CreateDefaultSubobject<UNiagaraComponent>("Confetti");
	Confetti->SetupAttachment(Root);

	//Création des bobines
	BobineGauche = CreateDefaultSubobject<UStaticMeshComponent>("BobineGauche");
	BobineGauche->SetupAttachment(Reels);
	BobineCentre = CreateDefaultSubobject<UStaticMeshComponent>("BobineCentre");
	BobineCentre->SetupAttachment(Reels);
	BobineDroite = CreateDefaultSubobject<UStaticMeshComponent>("BobineDroite");
	BobineDroite->SetupAttachment(Reels);

	//Renseignement des bobines dans le TArray pour qu'elles tournent
	//Ici ou BeginPlay, idk -> demander prof + optimal
	bobines.Add(BobineGauche);
	bobines.Add(BobineCentre);
	bobines.Add(BobineDroite);

	//Création des éléments du levier
	Junction = CreateDefaultSubobject<UStaticMeshComponent>("Junction");
	Junction->SetupAttachment(Levier);
	Arm = CreateDefaultSubobject<UStaticMeshComponent>("Arm");
	Arm->SetupAttachment(Levier);
	Hand = CreateDefaultSubobject<UStaticMeshComponent>("Hand");
	Hand->SetupAttachment(Levier);
}

// Called when the game starts or when spawned
void ASlot_Machine::BeginPlay()
{
	Super::BeginPlay();	

	//Enregistrement des matériaux
	FString matWinPath = "/Game/FirstPerson/Assets/mat_win";
	FString matCasualPath = "/Game/FirstPerson/Assets/mat_casual";
	mat_win = Cast<UMaterialInterface>(LoadObject<UMaterialInterface>(nullptr, *matWinPath));
	mat_casual = Cast<UMaterialInterface>(LoadObject<UMaterialInterface>(nullptr, *matCasualPath));
	
	//Enregistrement des sons dans les variables
	FString soundUsed = "/Game/FirstPerson/Assets/SlotMachine_tirage";
	FString soundWin = "/Game/FirstPerson/Assets/SlotMachine_win";
	spinning = Cast<USoundBase>(LoadObject<USoundBase>(nullptr, *soundUsed));
	winning = Cast<USoundBase>(LoadObject<USoundBase>(nullptr, *soundWin));
	if(IsValid(winning)) //Vérification si le son à été trouvé sinon pas de son -> Empêche bug
	{
		Speaker->SetAutoActivate(false);
		Speaker->SetSound(winning);
	}

	//Enregistrement du NiagaraSystem pour les confettis
	FString ns_confetti = "/Game/FirstPerson/Assets/NS_Confetti";
	UNiagaraSystem* ns = Cast<UNiagaraSystem>(LoadObject<UNiagaraSystem>(nullptr, *ns_confetti));
	if(IsValid(ns))	//Vérification si le NiagaraSystem est trouvé sinon rien -> Empêche bug
	{
		Confetti->SetAutoActivate(false);
		Confetti->SetAsset(ns);
	}
}

// Called every frame
void ASlot_Machine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	float newAngle = leverAngle - DeltaTime * 20.0f;
	leverAngle =  newAngle <= 0.0f ? 0.0f : newAngle;
	float lerpedValue = FMath::Lerp(leverAngle, 45.0f, 0.0f);
	Levier->SetRelativeRotation(FRotator(0, 0, lerpedValue));
}

void ASlot_Machine::SpinAllReels()
{
	for(auto& mesh : bobines)
	{
		indexes.Add(Spin(mesh));
		//UE_LOG(LogTemp, Display, TEXT("%d = %d"), indexes.Num() - 1, indexes[indexes.Num() - 1]);
	}
	isWinner();
	//Reset des index
	indexes.Empty();
}

int ASlot_Machine::Spin(UStaticMeshComponent* bobine)
{
	int index = rand() % 15 + 1;
	const float angle = 22.5f;
	float newAngleBobine = index * angle;
	bobine->SetRelativeRotation(FRotator(0, newAngleBobine, 0));
	return index;
}

void ASlot_Machine::ChangeMaterial(UMaterialInterface* mat)
{
	if(IsValid(mat))
		Ligne->SetMaterial(0, mat);
}

void ASlot_Machine::isWinner()
{
	//Compare valeur de la bobine gauche 0 à celle du centre 1
	//Bobine droite 2 ignorée
	if(indexes[0] == indexes[1])
	{
		Speaker->Play();
		ChangeMaterial(mat_win);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			this,								// WorldContextObject
			Confetti->GetAsset(),				// SystemTemplate
			Confetti->GetComponentLocation()	// Location
			);
	}
	else
	{
		ChangeMaterial(mat_casual);
	}
}

void ASlot_Machine::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
                              bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                              const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	if(leverAngle == 0.0f)
	{
		leverAngle = 45.0f;
		Levier->SetRelativeRotation(FRotator(0, 0, leverAngle));
		//Si le speaker est en train de jouer, on stoppe sinon rien
		if(Speaker->IsPlaying())
			Speaker->Stop();
		//Si le son est enregistré, joue le son
		if(IsValid(spinning))
			UGameplayStatics::PlaySoundAtLocation(this, spinning, this->GetActorLocation());
		SpinAllReels();
	}
}

