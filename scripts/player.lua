include("core/math")
include("core/entity")
include("core/input")

function Player()
   local self = Entity("box.jpg", "player")
   self.speed = 4;

   self.set_pos(5,5,-1)
   function self.update(dt)

      if get_key(keys.UP) then
	 self.translate(0, self.speed * dt,0)
      elseif get_key(keys.DOWN) then
	 self.translate(0, -self.speed * dt,0)
      end

      if get_key(keys.LEFT) then
	 self.translate(-self.speed * dt,0,0)
      elseif get_key(keys.RIGHT) then
	 self.translate(self.speed * dt,0,0)
      end
   end


   function self.on_collision(other,data)
      print("yay")
   end

   function self.on_trigger(other, data)
      print("i am triggered")
      other.destroy()
   end

   return self
end
