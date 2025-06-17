// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
#include "ABGameMode.h"
#include "Player/ABPlayerController.h"
#include "ArenaBattle.h"
#include "ABGameState.h"

AABGameMode::AABGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/Engine.Blueprint'/Game/ArenaBattle/Blueprint/BP_ABCharacterPlayer.BP_ABCharacterPlayer_C'"));
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/ArenaBattle.ABPlayerController"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}

	// ����� GameState ����
	GameStateClass = AABGameState::StaticClass();
}

void AABGameMode::OnPlayerDead()
{

}

/**
 * ������ �����Ϸ��� �÷��̾ �����ϰų� �ź���
 * ErrorMessage�� �� ���ڿ��� �ƴ� ������ �����ϸ� �ش� �÷��̾�� �α��ο� ������
 * PreLogin�� Login���� ���� ȣ���
 * ���� Login�� ȣ��Ǳ���� ����� ���� �ð��� �带 �� ����
 *
 * @param	Options					�÷��̾ ������ URL �ɼǵ� (��: �̸�/������ ��� ��)
 * @param	Address					�÷��̾��� ��Ʈ��ũ �ּ�
 * @param	UniqueId				�÷��̾ ������ ������ ���� ID
 * @param	ErrorMessage			�� ���ڿ��� �ƴ� ������ �����Ǹ�, �ش� ���� �޽����� ����� �÷��̾��� ������ �ź�
 */
void AABGameMode::PreLogin(const FString& Options,
	const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}

/**
 * ���ο� �÷��̾��� �α����� ó���ϱ� ���� ȣ��Ǹ�, ���ӿ��� override�� �� ����
 *
 * �÷��̾��� �⺻ �Ӽ�(�̸�, ���� ID, �鿣�� ��� ��)�� �����ϸ�, ������ ���� ������ �����ؼ��� �� ��
 * �� �Լ� �������� ��Ʈ��ũ �������� PlayerController�� ������ �ʱ�ȭ���� ���� ������
 * ���� ���� ������ ���Ŀ� ȣ��Ǵ� PostLogin���� ó���ؾ� ��
 *
 * @param NewPlayer �� �÷��̾ ��Ÿ���� UPlayer ��ü�� ���� ������ (���� �Ǵ� ����)
 * @param RemoteRole �� ��Ʈ�ѷ��� ������ ���� ����
 * @param Portal Ŭ���̾�Ʈ�� ������ ��Ż ��ġ
 * @param Options Ŭ���̾�Ʈ�� �α��� �� ������ ���� �ɼǵ�
 * @param UniqueId �α����ϴ� �÷��̾��� �÷��� ���� �ĺ���
 * @param ErrorMessage [���] �α��� ���� �� ������ �Ǵ� ���� �޽���
 *
 * �α����� �����ϸ�, �� �÷��̾�� ������ ���ο� PlayerController�� ��ȯ��
 * ErrorMessage ���ڿ��� �����Ǹ� �α����� ������
 *
 * @return �α����� �÷��̾ ���� ���ο� PlayerController, ������ ��� NULL ��ȯ
 */
APlayerController* AABGameMode::Login(UPlayer* NewPlayer,
	ENetRole InRemoteRole, const FString& Portal, const FString& Options,
	const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	APlayerController* NewPlayerController = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));

	return NewPlayerController;
}

/**
 * �α��ο� ������ �� ȣ���
 * �� �������� PlayerController���� ����(replicated) �Լ��� �����ϰ� ȣ���� �� ����
 */
void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::PostLogin(NewPlayer);

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}

/**
 * �� �ݹ��� ȣ��� �� ���͵鿡 ���� BeginPlay�� ȣ���ϴ� �ܰ�� ��ȯ��
 */
void AABGameMode::StartPlay()
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::StartPlay();

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}

