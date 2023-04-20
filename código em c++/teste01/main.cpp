#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>

// Definição da janela
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Exemplo DirectX 3D"

// Definição do ID do botão
#define BUTTON_ID 1

// Variáveis globais do Direct3D
LPDIRECT3D9 g_pD3D = NULL;
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;
LPD3DXFONT g_pFont = NULL;

// Função de inicialização do Direct3D
HRESULT InitD3D(HWND hWnd)
{
    // Cria o objeto Direct3D
    g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
    if (!g_pD3D)
        return E_FAIL;

    // Define a estrutura de apresentação
    D3DPRESENT_PARAMETERS d3dpp = {};
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.BackBufferWidth = WINDOW_WIDTH;
    d3dpp.BackBufferHeight = WINDOW_HEIGHT;

    // Cria o dispositivo Direct3D
    HRESULT hr = g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice);
    if (FAILED(hr))
        return hr;

    // Cria a fonte Direct3D
    D3DXCreateFont(g_pd3dDevice, 18, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
        "Arial", &g_pFont);

    return S_OK;
}

// Função de desenho do Direct3D
void Render()
{
    // Limpa o buffer de fundo
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

    // Começa a cena
    g_pd3dDevice->BeginScene();

    // Desenha a mensagem "Olá, Mundo!" usando a fonte Direct3D
    RECT rc = { 10, 50, 0, 0 };
    g_pFont->DrawText(NULL, "Olá, Mundo!", -1, &rc, DT_LEFT | DT_TOP, D3DCOLOR_XRGB(255, 255, 255));

    // Finaliza a cena
    g_pd3dDevice->EndScene();

    // Apresenta o buffer na tela
    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

// Função de liberação do Direct3D
void CleanupD3D()
{
    if (g_pFont)
        g_pFont->Release();
    if (g_pd3dDevice)
        g_pd3dDevice->Release();
    if (g_pD3D)
        g_pD3D->Release();
}

// Função de manipulador de mensagem
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == BUTTON_ID)
        {
            MessageBox(hWnd, "Olá, Mundo!", "Mensagem", MB_OK | MB_ICONINFORMATION);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}
// Função principal
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    // Registra a classe da janela
    WNDCLASSEX wcex = {};
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.lpszClassName = "DirectX3DWindowClass";
    RegisterClassEx(&wcex);

    // Cria a janela
    HWND hWnd = CreateWindow("DirectX3DWindowClass", WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);
    if (!hWnd)
        return E_FAIL;

    // Inicializa o Direct3D
    if (FAILED(InitD3D(hWnd)))
    {
        MessageBox(hWnd, "Falha ao inicializar o Direct3D", "Erro", MB_OK | MB_ICONERROR);
        return E_FAIL;
    }

    // Cria o botão
    CreateWindow("BUTTON", "Clique-me!", WS_VISIBLE | WS_CHILD,
        10, 10, 100, 30, hWnd, (HMENU)BUTTON_ID, hInstance, NULL);

    // Exibe a janela
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Loop de mensagem
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Libera os recursos do Direct3D
    if (g_pFont)
        g_pFont->Release();
    if (g_pd3dDevice)
        g_pd3dDevice->Release();
    if (g_pD3D)
        g_pD3D->Release();

    return (int)msg.wParam;
}
