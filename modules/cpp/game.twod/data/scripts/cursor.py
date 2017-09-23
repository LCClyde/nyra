import nyra.game2d as nyra

class Cursor(nyra.Actor2D):
    def update(self, delta):
        mouse_pos = nyra.Vector2D(nyra.input.value('x'), nyra.input.value('y'))
        tilemap = nyra.map.get_actor('tilemap')
        self.position = tilemap.tile_to_position(tilemap.get_cam_tile(mouse_pos))
