use sdl2::keyboard::Keycode;
use sdl2::keyboard::Scancode;
use std::collections::HashSet;
use sdl2::EventPump;

pub struct Input {
    key_states: HashSet<Scancode>,
}

impl Input {
    pub fn event(&mut self, engine: &Engine) {
        for event in engine.sdl_event_pump.poll_iter() {
            match event {
                Event::Quit {..} => engine.stop(),
                Event::KeyDown { keycode: Some(Keycode::Escape), .. } => {
                    self.is_running = false;
                },
                Event::KeyUp {..} => self.update_key_states(),
                Event::KeyDown {..} => self.update_key_states(),
                _ => {}
            }
        }
    }

    pub fn update_key_states(&mut self, e: &EventPump) {
        key_states = e.keyboard_state().pressed_scancodes()
                          .filter_map(Keycode::from_scancode)
                          .collect();
    }

    pub fn get_key_state(&self, key: Scancode) -> bool {
        key_states[key]
    }
}

pub fn new(e: &EventPump) {
    Input { key_states: e.keyboard_state().pressed_scancodes()
            .filter_map(Keycode::from_scancode)
            .collect(); }
}
