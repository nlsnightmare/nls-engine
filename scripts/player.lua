include("core/entity")
include("core/input")

function Player()
   local self = Entity("awesomeface.png", "player")
   self.speed = 4;

   function self.update(dt)

      if get_key(keys.W) then
	 self.translate(0, self.speed * dt,0)
      elseif get_key(keys.S) then
	 self.translate(0, -self.speed * dt,0)
      end

      if get_key(keys.A) then
	 self.translate(-self.speed * dt,0,0)
      elseif get_key(keys.D) then
	 self.translate(self.speed * dt,0,0)
      end


   end

   return self
end
