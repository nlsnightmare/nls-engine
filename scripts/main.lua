include("core/input")
include("core/entity")
include("player")
local player = Player()
for i = 1,10 do
   local e = Entity("box.png", "box"..i)

   e.set_pos(i,0,0)

end

local x = 0
local dx = 3

function update(dt)
   for _,e in pairs(entities) do
      e.update(dt)
   end

   for i=1,#entities do
      for j = i+1,#entities do
	 if entities[i].intersects(entities[j]) then
	    entities[i].on_collision(entities[j])
	    entities[j].on_collision(entities[i])
	 end
      end
   end
end
