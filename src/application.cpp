#include "application.hpp"

application::application(int argc, char **argv) {
  curl_global_init(CURL_GLOBAL_ALL);
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_TIMER | SDL_INIT_VIDEO);
  PHYSFS_init(argv[0]);
}

int application::run() {
  try {
    // filesystem::mount("bundle.zip", "/");
    // audiomanager am;
    // am.play("music.aac");

    auto se = scriptengine();
    se.run();

    // auto factory = enginefactory().set_title("Carimbo").set_width(800).set_height(600).set_fullscreen(false);

    // auto e = factory.create();
    // e->run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}

application::~application() {
  PHYSFS_deinit();
  SDL_Quit();
  curl_global_cleanup();
}