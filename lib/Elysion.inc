
// Compiler switches
// Use it wisely, only if you know what you're doing
// With great power comes great responsibility

// Use GLFW for window and input instead of SDL
{.$DEFINE USE_GLFW}

// To use PNGs, JPGs, GIFs, etc. instead of just BMPs
{.$DEFINE USE_SDL_IMAGE}
{$DEFINE USE_VAMPYRE}

{$IFNDEF DARWIN}
  {$DEFINE USE_DGL_HEADER}
{$ENDIF}

{$IFDEF MSWINDOWS}
  {$DEFINE WINDOWS}
{$ENDIF}

{$IFDEF FPC}
  {$INLINE ON}

  {$DEFINE CAN_METHODS}
  {$DEFINE CAN_INLINE}
{$ELSE}
  {$IFDEF VER170}
    {$DEFINE DELPHI2005UP}
  {$ENDIF}
  {$IFDEF VER180}
    {$DEFINE DELPHI2005UP}
  {$ENDIF}
  {$IFDEF VER185}
    {$DEFINE DELPHI2005UP}
  {$ENDIF}
  {$IFDEF VER200}
    {$DEFINE DELPHI2005UP}
  {$ENDIF}
  
  {$IFDEF DELPHI2005UP}
    {$DEFINE CAN_METHODS}
    {$DEFINE CAN_INLINE}
  {$ENDIF}
{$ENDIF}

{$IFDEF WINDOWS}
  {.$DEFINE WIIREMOTE}
{$ENDIF}

{$DEFINE AUTO_LINK}

{$IFDEF AUTO_LINK}
	// Links automatically to frameworks under Mac OS X
	{$IFDEF DARWIN}
		{$PASCALMAINNAME SDL_main} // Needed for Snow Leopard
		{$linklib SDLmain}

		  {$linkframework Cocoa}
		  {$linkframework SDL}
		  {$linkframework OpenGL}

		  //{$IFDEF USE_SDL_IMAGE} {$linkframework SDL_image} {$ENDIF}
		  //{$IFDEF USE_SDL_MIXER} {$linkframework SDL_mixer} {$ENDIF}
		  //{$IFDEF USE_SDL_GFX}   {$linkframework SDL_gfx}   {$ENDIF}
		  //{$IFDEF USE_SDL_NET}   {$linkframework SDL_net}   {$ENDIF}
	{$ENDIF}

{$ENDIF}

// Initializes container objects (Font container, Application container) by default
{$DEFINE AUTO_INIT}
